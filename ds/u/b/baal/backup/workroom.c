#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",MAG"������A�G�������J�f"NOR);

 set("long",@LONG
�o�̬O������A�G�������J�f, �A�e���ݥߵۤ@���K��, �K���W���
�·t���Z��J�起���L�O, �j�}���K�����������X�������H��, �X�ӫH�^
�·t���Z��J�起���q���~�ǰt�������Y�s�@���ųQ�s�ê���b�a�W, �a
�W��B�O���N�L���J�²���, �@�ѳ��t���𮧸n�۳o�y����, �O�H���H��
�X...

LONG
    );
 set("exits",([ "wiz":"/d/wiz/hall1",
                "enter":"/u/b/baal/workroom2",
                "ptstart":"/open/world1/tmr/area/hotel",
    ]));
        set("no_fight", 1);
        set("objects", ([ 
          __DIR__"weapon/darkamulet" : 5,
        ]));
        set("outdoors","land");
        set("light",1);
 set("no_clean_up", 1);
 setup();
 replace_program(ROOM);
 

}

