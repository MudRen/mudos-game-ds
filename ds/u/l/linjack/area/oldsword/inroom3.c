#include <room.h>
inherit ROOM;
void create()
{
 set("short","��D���");
 set("long",@LONG
�o�N�O�V����Ѱ�D����ǤF, �̭����\�], �H��D
�������ӻ��ٺ�ᬰ²��, �u�ݪ���X���j��M�X�ӥj��,
��W�����O�w�����ҤH�e��, �ڻ��O�L�ˤ�ҵe��. �o��
�\�]��²��, �i��O�l�Э覺�@�~�h���ҤH�a. �A�i�H��
���D���b�̭��e�e���֪��𮧵�.
LONG
    );
 set("exits",([
               "east":__DIR__"inroom1",]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
