#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s���W");
 set("long",@LONG
�o����@�K, �٦��ǳ���M�����̦b�o�䭸�R, �A�n��
�i�J�F�@�ӥ@�~�緽, �Ů�ǨӤ@�ѫիժ�����, �A�C�C����
�۳o�q�s��, ���A�Pı�M�s�r��.
LONG
    );
 set("exits",([
               "south":__DIR__"hall1",
               "westup":__DIR__"mount10",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
