# IMORTAL-1 - Sistema de Bordo (C)

Sistema de terminal para análise de três leituras numéricas (ex.: sensores), com média, extremos, desvios, verificação de faixa e relatório completo formatado com cores ANSI.

## Funcionalidades

- **Média** — calcula a média aritmética das três leituras.
- **Máximo/Mínimo** — identifica a maior e a menor leitura.
- **Desvios** — mostra a distância de cada leitura em relação à média (positivo = acima, negativo = abaixo).
- **Verificação de faixa** — usuário define um mínimo e um máximo aceitáveis; cada leitura é marcada em verde (`OK`) ou vermelho (`ACIMA`/`ABAIXO DO LIMITE`).
- **Barra gráfica** — representa a intensidade média com asteríscos (limitado a 20).
- **Relatório completo** — executa todas as análises acima em sequência.
- **Nova simulação** — permite repetir o processo com novos valores sem reiniciar o programa.

## Compilação

```bash
gcc -o sistema_bordo sistema_bordo.c
```

## Execução

```bash
./sistema_bordo
```

> As cores usam sequências ANSI (`\033[...m`); em terminais que não suportam ANSI (ex.: alguns prompts do Windows sem ajuste), os códigos aparecerão como texto.

## Fluxo de uso

1. Informa as três leituras.
2. Escolhe uma opção no menu (1–6) ou sai (0).
3. Pode repetir operações com os mesmos valores ou iniciar nova simulação com valores diferentes.

## Limitações conhecidas

- Sem validação de entrada não numérica em `scanf` (comportamento indefinido se o usuário digitar texto onde se espera número).
- Opção "6 - Relatorio completo" pede min/max aceitáveis internamente, duplicando a lógica já usada na opção "4 - Verificacao de faixa".
- `verificarFaixa` repete o mesmo bloco de comparação três vezes (uma por leitura) em vez de usar um loop.
- Sem persistência — nenhum dado é salvo em arquivo entre execuções.
