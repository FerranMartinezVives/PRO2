node_pila* copia_node_pila_it(node_pila* m) {
  if (m == nullptr) return nullptr;
  else {
    node_pila* n = new node_pila;
    n->info = m->info;
    node_pila* ant = n;
    m = m->seguent;
    while (m != nullptr) {
      node_pila* aux = new node_pila;
      aux->info = m->info;
      ant->seguent = aux;
      ant = aux;
      m = m->seguent;
    }
    ant->seguent = nullptr;
    return n;
  }
}

Pila& operator=(const Pila& original) {
  if (this != &original) {
    altura = original.altura;
    esborra_node_pila_it(primer_node);
    primer_node = copia_node_pila_it(original.primer_node);
  }
  return *this;
}
