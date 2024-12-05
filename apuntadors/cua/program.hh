void concat(Cua& c) {
  if (c.longitud > 0) {
    if (longitud == 0) {
      primer_node = c.primer_node;
      ultim_node = c.ultim_node;
      longitud = c.longitud;
    }
    else {
      ultim_node->seguent = c.primer_node;
      ultim_node = c.ultim_node;
      longitud += c.longitud;
    }
    c.primer_node = c.ultim_node = nullptr;
    c.longitud = 0;
  }
}
