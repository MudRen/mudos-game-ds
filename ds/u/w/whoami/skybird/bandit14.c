#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","�]�_��");
 set("long",@LONG 
�o�̴N�O�Q�U�s��s��]�_���a��F, �|�P��èS������ȱo
�`�N�������άO���ۤM�j���u��, �u�������F�ө����I�U���o�O.
�b�o�O���M�Ӥ��U, �P���_�c��o��~���ޤH�`��. 
LONG);
 set("exits",([ 
                "out":__DIR__"bandit11", 
    ]));
 set("objects", ([
                __DIR__"obj/red_box" : 1, 
                __DIR__"obj/orange_box" : 1,
                __DIR__"obj/yellow_box" : 1,
                __DIR__"obj/green_box" : 1,
                __DIR__"obj/blue_box" : 1,
                __DIR__"obj/indigo_box" : 1,
                __DIR__"obj/purple_box" : 1,
    ]));
 set("no_recall",1);
 set("no_clean_up",0);
 set("light",1);
 setup();

}

void door_closed()
{
   this_object()->delete("exits/out");
   tell_room(this_object(), HIW"�۪��y�I�z���@�n�A��M�Q���W�F�E\n"NOR);
   return;    
}

