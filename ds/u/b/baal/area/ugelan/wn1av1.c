#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�վB�����w�w�R���Ҥj�D(The Avenue of Elf)"NOR);
        set("long", @LONG
�����B�b��������t�a�a�A�w�R���Ҥj�D�����x�{�׸�
���ˤҡB�װҤj�D���D�n�F�D�ۤ�A�i�O�@�I�]������A��
���վB�����H�w�R���Ҥj�D�M�ڤڷ�w�j�D�����A�i�O�վB
���������F�����Ҧb�B�O�C
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"wn1av2",
                   "east" : __DIR__"fruitstore1",
                        "south": __DIR__"w1st1",
            ]));
           set("item_desc",([
"�]�k���O" : "
�@�ӷ����}�G�A�Ѭ����s�����]�k���O�A�̭������]�k�ҥl
���X�����V�A�ҥH���ݭn�U�ơA���O�C�L�@�q�ɶ��N�o�ѫ�
�����]�k�v���s�۳�~��C\n",
"����" : "�b�H��D���䪺�W�ѡA�`���@�`�A�̭��n�F�Ǿ𸭸�U���A
�i�b�U�B���������ɿn���ܤU���D�̡C\n",
                 ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}

