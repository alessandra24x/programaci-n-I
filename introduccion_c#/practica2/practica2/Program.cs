using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace practica2
{
    class Program
    {
        static void Main(string[] args)
        {
            Orquesta or = new Orquesta("Mario", "CABA", Orquesta.TipoOrquesta.Filarmonica);
            Console.WriteLine("Nombre: {0}, Lugar: {1}, Tipo: {2}", or.nombre, or.lugar, or.tipo);
            Console.ReadLine();

            Instrumento instrumento = new Instrumento("Guitarra", Instrumento.TipoInstrumento.Acustica);
            Console.WriteLine("Nombre: {0}, Tipo: {1}", instrumento.nombre, instrumento.tipo);
            Console.ReadLine();

            Musico musicoPrincipal = new Musico("Carla", "Perez", 26, instrumento);
            Console.WriteLine("Nombre del Musico: {0}, Apellido: {1}, Edad: {2}, \n Instrumento: {3}",
                            musicoPrincipal.nombre, musicoPrincipal.apellido, musicoPrincipal.edad,
                            musicoPrincipal.instrumento /*musicoPrincipal.orquesta.getOrquestaToString()*/);
            Console.ReadLine();

            Musico m2 = new Musico("Pepe", "Grillo", 24, instrumento);

            or.musicos.Add(musicoPrincipal);
            or. musicos.Add(m2);

            Orquesta.ImprimirOrquesta(or);
        }


    }
}
