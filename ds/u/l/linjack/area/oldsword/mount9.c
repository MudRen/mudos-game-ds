#include <room.h>
inherit ROOM;
void create()
{
 set("short","�n�s�~�|");
 set("long",@LONG
�s�Y�W������o��w�g���������F, ���a���դ]������j,
�}�U�����j�۶����A���_�o�q���ᬰ���P, ���L�A�V�����B��h
, �N�Vı�o�o�q���S����n��. ���B���s���q�J����, �A�Q���h
�è���쩳�O����?
LONG
    );
 set("exits",([
               "eastdown":__DIR__"mount10",
               "westup":__DIR__"mount8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
