#include <ansi.h>  
inherit ROOM;
 
void create()
{
  set("short", "���}�`�B - �L���p�D");
  set("long", @LONG
������@���A�b���·t���}�ޤ��A���G���ط������ƪ��ͪ��A
�F�F���n�T���_���o�X�C�A�`�N��o�䪺�����@�A�ٱa�۹äߪ���
�{���A�I�����I�R�n���A�V�[�Y��X�A���ߪ����ߡC
LONG
  );
  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"snake-room3",
     "down" : "/open/world1/tmr/wujian/snake-room6d",
     ]));
  set("no_clean_up", 0);
  setup();
}


