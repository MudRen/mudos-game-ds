#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�۶��W");
 set("long",@LONG
�A���b�@�ӷ����I�m���s���W, �۶����e�ץu����ؤ���, 
�ӥB���B���դ��p, �Y�O�ڰ򤣰����p, �L�kí���l, ���H
�ɦ����U�s�V���i��. �A�����b�A���䪺�������������}, �w
�g�i�H�M�����ݨ�{��ģ�����~���s���F.
LONG
    );
 set("exits",([
               "southdown":__DIR__"mount3",
               "northup":__DIR__"mount1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
