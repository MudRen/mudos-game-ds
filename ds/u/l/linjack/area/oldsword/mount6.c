#include <room.h>
inherit ROOM;
void create()
{
 set("short","���h����");
 set("long",@LONG
�A�J�Ӫ��n�۸}�U���۶�, ���n���A����Ū��ƥ�o��,
�]���q�o��^�U�h, �N�S�R�F. �A��ӤH�w�g���b���h����
�F, ���������ϧA�����ۦb, �۶���ƤF, �A���o�p�ߤ~
��A���W�h.
LONG
    );
 set("exits",([
               "northdown":__DIR__"mount7",
               "southup":__DIR__"mount5",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
