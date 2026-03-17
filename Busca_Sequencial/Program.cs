using System.Diagnostics;
User[] usuarios = new User[11]; 

usuarios[0] = new User(45, "Igor Daniel", "123.456.789-00");
usuarios[1] = new User(12, "Ana Costa", "234.567.890-11");
usuarios[2] = new User(89, "Marcos Silva", "345.678.901-22");
usuarios[3] = new User(23, "Beatriz Souza", "456.789.012-33");
usuarios[4] = new User(67, "Ricardo Oliveira", "567.890.123-44");
usuarios[5] = new User(34, "Julia Lins", "678.901.234-55");
usuarios[6] = new User(91, "Caio Martins", "789.012.345-66");
usuarios[7] = new User(05, "Fernanda Lima", "890.123.456-77");
usuarios[8] = new User(78, "Paulo Santos", "901.234.567-88");
usuarios[9] = new User(56, "Larissa Duarte", "012.345.678-99");

User Busca_sequencial_c_sentinela(User[] v, int id)
{
    int tamanho = v.Length - 1;
    v[tamanho] = new User(id, "Usuario Inexistente", "0");
    int i;
    for(i = 0;v[i].Id != id; i++);
    if(i == tamanho) return null; //Funciona para retor nulo e dar erro
    return v[i];

}

User Busca_sequencial_c_sentinela2(User[] v, int id)
{
    int tamanho = v.Length - 1;
    v[tamanho] = new User(id, "Usuario Inexistente", "0");
    int i;
    for(i = 0;v[i].Id != id; i++);
    return v[i];
}

User buscado = Busca_sequencial_c_sentinela(usuarios, 45);

buscado.Detalhes();

/*
User buscado2 = Busca_sequencial_c_sentinela(usuarios, 01);

buscado2.Detalhes(); Dá erro retornando NULL*/

Stopwatch sw = new Stopwatch();

Busca_sequencial_c_sentinela(usuarios, -1); 

// Medição
sw.Start();
for (int i = 0; i < 1000000; i++)
{
    Busca_sequencial_c_sentinela(usuarios, 30);
}
sw.Stop();

Console.WriteLine("\nBusca Sequencial com Sentinela Normal:\n");
Console.WriteLine($"Tempo total para 1 mi execuções: {sw.ElapsedMilliseconds}ms");
Console.WriteLine($"Tempo médio: {sw.Elapsed.TotalMilliseconds / 10000}ms\n");

Stopwatch sw2 = new Stopwatch();

Busca_sequencial_c_sentinela2(usuarios, -1); 

// Medição
sw2.Start();
for (int i = 0; i < 1000000; i++)
{
    Busca_sequencial_c_sentinela2(usuarios, 30);
}
sw2.Stop();

Console.WriteLine("Busca Sequencial com Sentinela Adaptado:\n");
Console.WriteLine($"Tempo total para 1 mi execuções: {sw2.ElapsedMilliseconds}ms");
Console.WriteLine($"Tempo médio: {sw2.Elapsed.TotalMilliseconds / 10000}ms");

//Conclusão o adaptado é mais lento porque retornar NULL é mais rápido que retornar o objeto.