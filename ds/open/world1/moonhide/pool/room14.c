#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "���H�P�}");
        set("long", @LONG
�}�������A�q�����_�̴�X�A�b�}���Φ��@�۬y�u�A��Ǫ���
�Y�G�F�F�p�}�A�����ٷ|�_�X�p���ɡA�b�a�W�����|�̡A�ٴ�۵L
�ƪ��p���B�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room17",  
  "north" : __DIR__"room13",]));
        set("no_clean_up", 0);

        setup();
}

