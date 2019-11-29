using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace practica2
{
    class Musico
    {
        public string nombre;
        public string apellido;
        public int edad;
        public Instrumento instrumento;
        //public Orquesta orquesta;

        public Musico(string nombre, string apellido, int edad, Instrumento inst) {
            this.nombre = nombre;
            this.apellido = apellido;
            this.edad = edad;
            this.instrumento = inst;
            //this.orquesta = or;
        }

        
    }
}
