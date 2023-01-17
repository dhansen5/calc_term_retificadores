### Projeto Cálculo Térmico em Retificadores operando em regime permanente###

---

O projeto faz o cálculo de algumas grandezas utilizadas no dimensionamento de dissipadores para componentes utilizados em retificadores considerando operação em regime permanente.

A potência dissipada pelo componente, é calculada a partir da queda de tensão sobre o mesmo em operação, sua corrente média e a eficaz, assim como sua resistência interna. Estes valores devem ser informados pelo usuário.

A partir da potência, é possivel o cálculo de um valor recomendado de dissipador. Para isso se faz necessário que o usuário entre com outros valores, onde
uma tabela apresentada no programa através de um arquivo de texto, pode auxiliar trazendo algumas caracteristicas dos encapsulamentos mais utilizados.

Este arquivo de texto com a tabela pode ser editado pelo usuario a fim de adicionar ou remover encapsulamentos, informando valores como a temperatura de junção máxima do componente e a temperatura ambiente em que o mesmo irá operar. Com isso já é possivel o cálculo da resistência térmica entre Junção-Ambiente.
É necessario também que o usuário informe a resistencia termica entre a junção-Cápsula e Cápsula-Ambiente.
Assim, é feito o cálculo da resistência térmica entre Junção-Dissipador e tambem a resistência térmica entre o Dissipador-Ambiente, que irá informar o dissipador recomendado para o retificador.

O usuário pode ainda ver a diferença entre a temperatura de junção do componente com e sem o dissipador e assim saber se o componente corre riscos de ser danificado caso não seja utilizado um dissipador.

E por fim, é possível gerar um arquivo de texto com os dados obtidos.
