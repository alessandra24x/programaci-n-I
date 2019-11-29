using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace practica2
{
    class Orquesta
    {
        public string nombre;
        public string lugar;
        public TipoOrquesta tipo;
        public List<Musico> musicos;

        public enum TipoOrquesta {Sinfonica, Camara, Filarmonica}

        //constructor sin parametros
        public Orquesta() { }

        //constructor con parametros
        public Orquesta(string nombre, string lugar, TipoOrquesta orquesta)
        {
            this.nombre = nombre;
            this.lugar = lugar;
            this.tipo = orquesta;
            this.musicos = new List<Musico>();
        }

        public string getOrquestaToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendFormat("Nombre Orquesta: {0}, Lugar: {1}, Tipo: {2},\n", this.nombre, this.lugar, this.tipo);
            return sb.ToString();
        }

        public static void ImprimirOrquesta(Orquesta or)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine(or.getOrquestaToString());
            if(or.musicos.Count > 0)
            {
                sb.AppendFormat("Lista de musicos: \n");
                foreach(Musico element in or.musicos)
                {
                    sb.AppendFormat("Musico: {0}", element.nombre);
                    sb.AppendFormat("Instrumento: {0}\n", element.instrumento.nombre);
                }
            }
            Console.WriteLine("{0}", sb.ToString());
            Console.ReadLine();
        }


    }
}
