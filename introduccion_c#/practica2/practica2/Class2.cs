using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace practica2
{
    class Instrumento
    {
        public string nombre;
        public TipoInstrumento tipo;

        public enum TipoInstrumento { Acustica, Electrica }

        public Instrumento() { }

        public Instrumento(string nombre, TipoInstrumento instrumento)
        {
            this.nombre = nombre;
            this.tipo = instrumento;
        }
    }
}
