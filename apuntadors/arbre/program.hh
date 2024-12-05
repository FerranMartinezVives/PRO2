void arb_sumes(Arbre<int> &asum) const {
  asum.primer_node = suma(primer_node);
}

node_arbre* suma(node_arbre* a) const {
  if (a == nullptr) return nullptr;
  else {
    node_arbre* b = new node_arbre;
    b->segE = suma(a->segE);
    b->segD = suma(a->segD);
    b->info = a->info;
    if (b->segE == nullptr and b->segD == nullptr) return b;
    else if (b->segE == nullptr) b->info += b->segD->info;
    else if (b->segD == nullptr) b->info += b->segE->info;
    else b->info += b->segE->info + b->segD->info;
    return b;
  }
}
