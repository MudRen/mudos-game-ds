#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�e���y�J�s�諸����A���y�J�M��w�A�a�ۤj�q�I�n���E���b
�o�̡A�]���A���쩥�h�������A��p�y�����Φ��n�X�Ӥ��D�A�C�C
�Φ����p���T���w�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room16",
  "south" : __DIR__"room20",
  "west" : __DIR__"pool",
  "north" : __DIR__"room18",]));
        set("no_clean_up", 0);

        setup();
}

