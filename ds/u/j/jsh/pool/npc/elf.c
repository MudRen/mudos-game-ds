#include <path.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name("���_�a��", ({ "dig-treasure earth_elf","elf" }) );
        set("gender", "beast" );
        set("age", "???");
        set("long","�����j���@�إb�����G�H�A�y�W���O�|�ͤΤj�j�p�p���СA���W����m�}�}���ꪺ\n"                   "���O����o�I�F�@�Ӷ��⪺�j���]�A�����D�ˤF�Ǥ���F��H\n");
        set("level",1); 
        set("no_kill",1);     
 
        set("attitude", "friendly");
        set("sell_list",([
                __DIR__"obj/shield" : 10, 
                __DIR__"obj/ten-sword": 10,
                __DIR__"obj/scroll":10,       
                __DIR__"obj/lbg":10,
  ]) );
        setup();
}  
void init()
{        
        object ob,el;
        el = this_object();  
        ::init();   
                if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }   
        add_action("do_buy","buy");
        add_action("do_list","list");  
  } 
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(7) ) {
                case 0:
                        say( "���_�a�뻡�G�A�O�H���O�a�H��������......�ӶR�ӤW�n�f�a...\n");
                        break;
                case 1:
                        say( "���_�a�뻡�G��������.....�Ѥl�{�b���Q��F��.....��|�L���� !!�C\n"); 
                        destruct(this_object());
                        break;
                case 2:
                        say( "���_�a�뻡�G�A�ݫ᭱�I(����A�ݫ᭱���ɭ�)�C\n"); 
                        say( "���_�a�뻡�G��������....�Q����H���o��¡I�I�A���� ~ ~\n");
                        destruct(this_object());
                        break; 
                case 3:
                        say( "���_�a�뻡�G�h�§A���G�l�� ~ ~ ~ �A�|�� ~ ~ ! !������....\n");
                        destruct(this_object());
                        break;  
                case 4:
                        say( "���_�a�뻡�G���r�r~~~�ڧѤF�˴��٨S����~~~~��������~~~�{�P~~~\n");
                        destruct(this_object());
                        break; 
                case 5:
                        say( "���_�a�뻡�G���R�Ȧb�s��ڤF������A�|�ա��I�I\n");
                        destruct(this_object());
                        break;
                case 6:
                        say( "���_�a�뻡�G�ڮa�U���٨S�ˡ������ڥ����ա���㫣������\n");
                        destruct(this_object());
                        break;     
 
  }
}

