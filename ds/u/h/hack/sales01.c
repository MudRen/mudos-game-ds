#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
 set_name( "���N", ({ "black eagle","eagle"}));
        set("long", "�L�O�c�F�b�Ȫ��U�ݡA¾�~�O��x���ӡA�B�֦����h���޹D�A
�b�L�o�̡A�L�׬O����˪��}�@�M�C�A���O�����ɦ��A�S��
�R���쪺�F��A�P�º��B�¿ߨæC�m�c�F�T�L�n�C\n\n"
        	             +"  �ݦs�f�Х� <list> \n"
        	             +"  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n\n"
        );
        set("level",50);
        set("title",HIR"�c�F�T�L"NOR);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("combat_exp",5000);
        set("evil",60);
set("sell_list",([	
           "/u/h/hack/wp/sevenstar.c"  :10,
        "/u/h/hack/wp/shangsword.c"  :10,    
        "/u/h/hack/wp/oldsword.c"    : 10, 
           "/u/h/hack/wp/sunsword.c"   : 10,  
         "/u/h/hack/wp/dab-aqua-claw.c"   : 10,  
         "/u/h/hack/wp/dragon-fist.c"   : 10,  
         "/u/h/hack/wp/lance.c"   : 10,  
         "/u/h/hack/wp/staff.c"   : 10,  
         "/u/h/hack/wp/sword2.c"   : 10,  
         "/u/h/hack/wp/blade.c"   : 10,  
        "/u/h/hack/wp/blade2.c"   : 10,  
        "/u/h/hack/wp/coldpike.c"   : 10,  
        "/u/h/hack/wp/darksword.c"   : 10,  
        "/u/h/hack/wp/evilsword.c"   : 10,  
        "/u/h/hack/wp/masterfork.c"   : 10, 
       "/u/h/hack/wp/s_blade.c"   : 10, 
     "/u/h/hack/wp/moon_tooth.c"   : 10,
     "/u/h/hack/wp/staff.c"   : 10,
     "/u/h/hack/wp/seven-staff.c"   : 10,
 ]) );		


        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("talk_reply","�b�ڳo�̨S���R���쪺�Z��..�K�K�K..");
     
 setup();

      add_money("coin", 120);		//�a����
      
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
}

	