#include <room.h>
inherit ROOM;
void create()
{
 set("short","�ĤG�N�̤l�Q");
 set("long",@LONG
�o��O�V����ĤG�N�̤l���ɥ𮧪��a��, �ж��ٺ�e��,
�i�H�e�U�C�K�ӤH��. �̭��u���T�W�ĤG�N�̤l�b�o��m�\,
���F�קK�A�ΫI�Z, �L�̳����\�A���b�̭�.
LONG
    );
 set("exits",(["south":__DIR__"inroom49",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
