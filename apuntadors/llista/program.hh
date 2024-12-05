node_llista* copia_node_llista_it (node_llista* m, node_llista* oact, node_llista* &u, node_llista* &a) {
  if (m == nullptr) {
    u = nullptr;
    a = nullptr;
    return nullptr;
  }
  else {
    node_llista* n = new node_llista;
    n->info = m->info;
    node_llista* aux1 = n;
    m = m->seg;
    while (m != nullptr) {
      node_llista* aux2 = new node_llista;
      aux2->info = m->info;
      aux1->seg = aux2;
      aux2->ant = aux1;
      aux1 = aux2;
      if (m == oact) a = aux1;
      m = m->seg;
    }
    aux1->seg = nullptr;
    u = aux1;
    return n;
  }
}

Llista& operator=(const Llista& original) {
  if (this != &original) {
    longitud = original.longitud;
    esborra_node_llista_it(primer_node);
    primer_node = copia_node_llista_it(original.primer_node, original.act, ultim_node, act);
  }
  return *this;
}
