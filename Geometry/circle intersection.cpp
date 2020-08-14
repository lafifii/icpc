bool intersecta(int x1, int y1, int r1, int x2, int y2, int r2) { 
    int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); 
    int rad = (r1 + r2) * (r1 + r2); 
    if(d >= rad) return false; // = si es en extremos
    return true; 
} 
