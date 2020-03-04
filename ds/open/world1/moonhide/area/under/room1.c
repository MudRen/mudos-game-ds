#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
�o�̬O�@�����˺��ª��q�D�A����ť��w�������n�A�Y���Y�L�a
�����A����Ŧ�A��M�@�}�H�N�q�A�I��«�W�����C�A���G�Pı�즳��
�¼v�q�e�誺�ਤ�@�{�ӹL�A���A�߸̤��TŸ�F�@�U�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "south" : __DIR__"startroom", 
            "north" : __DIR__"room2",
            "southwest" : __DIR__"room_1",
            "southeast" : __DIR__"room-1",]));
        set("no_light",1);
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/leggings-guard" : 1,
           ]));
        setup();
        replace_program(ROOM);
}
