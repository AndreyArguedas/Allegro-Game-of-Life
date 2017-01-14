#include "GraphicInterface.h"


GraphicInterface::GraphicInterface(void)
{
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_mouse();
	al_install_audio();
	al_init_acodec_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_set_new_display_flags(ALLEGRO_RESIZABLE|ALLEGRO_WINDOWED);
	display = al_create_display(1300,700);
	al_set_window_title(display,"GAME OF LIFE");
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
}

void GraphicInterface::start(){
	ALLEGRO_FONT * font_48 = al_load_font("Black.ttf",36,NULL);
	al_draw_filled_rectangle(800,0,1300,700,al_map_rgb(0,0,0));
	al_draw_text(font_48,al_map_rgb(76,145,65),1000,150,ALLEGRO_ALIGN_CENTRE,"RIGHT CLICK TO");
	al_draw_text(font_48,al_map_rgb(76,145,65),1000,250,ALLEGRO_ALIGN_CENTRE,"GENERATE LIFE");
}

void GraphicInterface::timesLeft(int tl){
	stringstream convert;
	convert << tl;
	string r = convert.str();
	al_draw_filled_rectangle(800,0,1300,700,al_map_rgb(0,0,0));
	ALLEGRO_FONT * font_48 = al_load_font("Black.ttf",36,NULL);
	al_draw_text(font_48,al_map_rgb(76,145,65),1000,150,ALLEGRO_ALIGN_CENTRE,"GENERATIONS LEFT");
	al_draw_text(font_48,al_map_rgb(76,145,65),1000,250,ALLEGRO_ALIGN_CENTRE,r.c_str());
}


void GraphicInterface::printPlatform(string plat){
	int r = 0;int c = 0;
	int aux = plat.length();

	for(int i = 0; i < plat.length(); i++)
		if (plat[i] == 'O') {
			al_draw_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(255,255,255),1);
			al_draw_filled_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(76,145,65));
			r++;
		}
		else if(plat[i] == '-'){
			al_draw_filled_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(0,0,0));
			al_draw_rectangle(r * 40,c * 40,r * 40 + 40,c * 40 + 40,al_map_rgb(255,255,255),1);
			r++;
			
		}
		else if(plat[i] == '\n'){
				r = 0; 
				c++;
		}
	al_flip_display();
}

GraphicInterface::~GraphicInterface(void)
{
	al_destroy_display(display);
}
