inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"�W���F"NOR);
        set("no_fight", 1);
  set("light",1);
        set("long", @LONG

    ���F�|�P�Q�f�ѤѡA�צ˱`�C�A�s�ۨq�R�A�Ѥ����y�A�@���g�H��
���n����C�Ӥj�U���ߦ��}��칳�A���G���u�w�ۡu��������׻����A
�^�N�W�U�ӨD���v���d�j�Υy�C��Ǫ��U�W�h�a���M�³��C�v���g����
�p�G
          �s�r�کt���A�T�ʽg���W�v�ܶ��}�s��F
          �h�F�I���a�A��d�~��ߦ��y�n���®ɡC

LONG
        );
    set("exits",([
 "out" : __DIR__"room02",
]));
        set("objects", ([ 
  __DIR__"mob03" : 1,
]));
        set("no_clean_up", 1);
        setup();
        replace_program(ROOM);
}
