#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�վB�����w���ˤҤj�D(The Avenue of Dwarf)"NOR);
        set("long", @LONG
�A�����B��վB�����~�����F��V�D�n�F�D�w���ˤҤj
�D���W�A�D���H�C�۪O�Q���A�i�H�ݥX�O�g�L�]�p���A����
�W�U���i�ѤQ�������P�ɦ樫���e�סA�b�D���W�C�g�L�@�q
���קY�i�o�{�H�K�s�����U���D�\�A�b�D����ǻP��ǤH��
�D�����S�U���@�������A�H�b�U�B�ɲ��q�n���i�a�U���D�A
�̫�~�O�U�e����̪��H��D�A�ӤH��D�W�h�شӵ۸g�ѱM
�H�װŪ������A���o�۰}�}�խ��A���ݦp���W���A�K�i
�P���즹�a���\�O���̤j�������F�I�I
LONG
        );
        set("exits", ([ 
                        "west": __DIR__"w1st1",
            "east": __DIR__"w1st3",
            ]));
        set("outdoors","land");
           set("item_desc",([
"�]�k���O" : "
�@�ӷ����}�G�A�Ѭ����s�����]�k���O�A�̭������]�k�ҥl
���X�����V�A�ҥH���ݭn�U�ơA���O�C�L�@�q�ɶ��N�o�ѫ�
�����]�k�v���s�۳�~��C\n",
"����" : "�b�H��D���䪺�W�ѡA�`���@�`�A�̭��n�F�Ǿ𸭸�U���A
�i�b�U�B���������ɿn���ܤU���D�̡C\n",
                 ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
}

