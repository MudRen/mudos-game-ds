#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�۶��W");
 set("long",@LONG
�A�J�Ӫ��n�۸}�U���۶�, ���n���A����Ū��ƥ�o��,
�]���q�o��^�U�h, �N�S�R�F. �A�Pı�����w�g�����֤F,
�ӦV�e�����u�]�K�����M�R��, ���������S�j�F�_��, �q�A
���Y, �C�C�j��y, �A�ӬO�}.
LONG
    );
 set("exits",([
               "westdown":__DIR__"mount4",
               "northup":__DIR__"mount2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
