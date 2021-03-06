/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 


/* some random function to test function pointer */ 
color sc(object* o, location intersection) { 

       return color_expr(0, 0, 0); 
} 

/* testing stage functions */ 
void evidence_stage() { 

    printf("\nTesting Stage\n"); 
    
    //code for making the scene for stage 
    xyz ulc = xyz_expr(0, 0, 0); 
    double w = 1.5, h = 1;  
    color shine = color_expr(0.1, 0.1, 0.1); 
    color (*surface_color)(object*, location) = &sc; 
    location v = xyz_expr(0, 0, 0); 
    double r = 3;  
    
    poster p = poster_expr(ulc, w, h, surface_color, shine); 
    sphere s = sphere_expr(v, r, surface_color, shine);    
    
    object op; 
    op.tag = POSTER;
    op.o.p = p; 

    object os;
    os.tag = SPHERE; 
    os.o.s = s; 

    obj_list* olist = ol_singleton(op); 
    olist = ol_cons(os, olist); 

    scene sc; 
    sc.objects = olist; 
    sc.bg = color_expr(0, 0, 0); 

    //code for making camera for stage */ 
    camera c = camera_expr(20, 30, xyz_expr(1, 1, 1) ); 

    //make stage 
    stage stg; 
    stg.s = sc;
    stg.c = c; 

    stage_show(stderr, stg); 
    
        
} 

int main() { 

    evidence_stage(); 
    return 0; 
} 

 
