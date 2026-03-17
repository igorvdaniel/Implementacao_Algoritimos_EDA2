class User
{
    public int Id { get;}
    public string Nome {get;}
    public string Cpf {get;}
    public User(int id, string nome, string cpf)
    {
        Id = id;
        Nome = nome;
        Cpf = cpf;
    }

    public void Detalhes()
    {
        Console.WriteLine($"Nome: {Nome} \nCPF: {Cpf}");
    }
}