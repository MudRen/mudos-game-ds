#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",HIC"�쮦���u�@�ǤJ�f"NOR);

 set("long",@LONG
�o�̬O�쮦�u�@�Ǫ��J�f, �A�e���ݥߵۤ@���K��, �K���W�w�g�ФW
�F�p�p���@�h��, ���䪺�[�l�W���۴X��O�x���ָ�, �W���]���\�ۤ@�h
����, ���G�O�ѤJ�����H�O�x�Ϊ�, �A�@�Ӭ�, �[�l�Ǳ��ۤ@�ӵP�l, �W
[D�g�y�����ūקC�����s��, �Ь�ָʤJ��, �H�K���. �z�A���T��o��
�u�@�Ǫ��֦��̷P��۷��n�_...
LONG
    );
 set("exits",([ "wiz":"/d/wiz/hall1",
                "area":"/u/i/ian/area/birdpill",
                "enter":"/u/i/ian/workroom2",
                "ptstart":"/open/world1/tmr/area/hotel",
    ]));
        set("no_fight", 1);
        set("light",1);
 set("objects",([
 "u/i/ian/weapon/furredrobe":5,
                 ]));
 set("no_clean_up", 1);
 setup();
 replace_program(ROOM);
 

}

