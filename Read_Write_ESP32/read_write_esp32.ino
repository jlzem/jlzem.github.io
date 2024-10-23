/*

Armazenamento de dados na memória flash do ESP32
https://www.makerhero.com/blog/armazenamento-de-dados-na-memoria-flash-do-esp32/

*/

/* Header-file com as funções utilizadas para
   manipulação da partição NVS */
#include "nvs.h"
#include "nvs_flash.h"

/* Definição - baudrate da serial de debug */
#define BAUDRATE_SERIAL_DEBUG    115200

/* Chave atribuida ao valor a ser escrito e lido
   da partição NVS */
#define CHAVE_NVS  "teste"

/* Protótipos */
void grava_dado_nvs(uint32_t dado);
uint32_t le_dado_nvs(void);

/* Função: grava na NVS um dado do tipo interio 32-bits
           sem sinal, na chave definida em CHAVE_NVS
   Parâmetros: dado a ser gravado
   Retorno: nenhum
*/
void grava_dado_nvs(uint32_t dado) {
  nvs_handle handler_particao_nvs;
  esp_err_t err;

  err = nvs_flash_init_partition("nvs");

  if (err != ESP_OK)   {
    Serial.println("[ERRO] Falha ao iniciar partição NVS.");
    return;
  }

  err = nvs_open_from_partition("nvs", "ns_nvs", NVS_READWRITE, &handler_particao_nvs);
  if (err != ESP_OK)   {
    Serial.println("[ERRO] Falha ao abrir NVS como escrita/leitura");
    return;
  }

  /* Atualiza valor do horimetro total */
  err = nvs_set_u32(handler_particao_nvs, CHAVE_NVS, dado);

  if (err != ESP_OK) {
    Serial.println("[ERRO] Erro ao gravar horimetro");
    nvs_close(handler_particao_nvs);
    return;
  } else {
    Serial.println("Dado gravado com sucesso!");
    nvs_commit(handler_particao_nvs);
    nvs_close(handler_particao_nvs);
  }
}

/* Função: le da NVS um dado do tipo interio 32-bits
           sem sinal, contido na chave definida em CHAVE_NVS
   Parâmetros: nenhum
   Retorno: dado lido
*/
uint32_t le_dado_nvs(void) {
  nvs_handle handler_particao_nvs;
  esp_err_t err;
  uint32_t dado_lido;

  err = nvs_flash_init_partition("nvs");

  if (err != ESP_OK) {
    Serial.println("[ERRO] Falha ao iniciar partição NVS.");
    return 0;
  }

  err = nvs_open_from_partition("nvs", "ns_nvs", NVS_READWRITE, &handler_particao_nvs);
  if (err != ESP_OK) {
    Serial.println("[ERRO] Falha ao abrir NVS como escrita/leitura");
    return 0;
  }

  /* Faz a leitura do dado associado a chave definida em CHAVE_NVS */
  err = nvs_get_u32(handler_particao_nvs, CHAVE_NVS, &dado_lido);

  if (err != ESP_OK) {
    Serial.println("[ERRO] Falha ao fazer leitura do dado");
    return 0;
  } else {
    Serial.println("Dado lido com sucesso!");
    nvs_close(handler_particao_nvs);
    return dado_lido;
  }
}

void setup() {
  uint32_t dado_a_ser_escrito = 123456;
  uint32_t dado_lido;

  /* Inicializa a serial de debug */
  Serial.begin(BAUDRATE_SERIAL_DEBUG);

  /* Escreve na NVS (na chave definida em CHAVE_NVS)
     o valor da variável "dado_a_ser_escrito" */
  Serial.print("Gravar dado: ");
  Serial.println(dado_a_ser_escrito);
  grava_dado_nvs(dado_a_ser_escrito);

  /* Le da NVS (na chave definida em CHAVE_NVS)
     o valor escrito e compara com o que foi escrito */
  dado_lido = le_dado_nvs();
  Serial.print("Dado Lido: ");
  Serial.println(dado_lido);

  if (dado_lido == dado_a_ser_escrito) {
    Serial.println("Sucesso: dado lido eh igual ao escrito");
  } else {
    Serial.println("Erro: dado lido nao eh igual ao escrito");
  }
}

void loop() {

  delay(1000);

}
