#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�վB�����w���ˤҤj�D(The Avenue of Dwarf)"NOR);
        set("long", @LONG
�A�����B��վB�����~�����F��V�D�n�F�D�w���ˤҤj
�D���W�A�V��i�H��L�u�ï��A���}�վB�����A�V�F�h�i��
���i�J�վB���������A�D���H�C�۪O�Q���A�i�H�ݥX�O�g�L
�]�p���A�����W�U���i�ѤQ�������P�ɦ樫���e�סA�b�D��
�W�C�g�L�@�q���קY�i�o�{�H�K�s�����U���D�\�A�b�D����
�ǻP��ǤH��D�����S�U���@�������A�H�b�U�B�ɲ��q�n��
�i�a�U���D�A�̫�~�O�U�e����̪��H��D�A���ݦp���W��
�A�K�i�P���즹�a���\�O���̤j�������F�I�I
LONG
        );
        set("exits", ([ 
            "west": __DIR__"wgate3",
            "east": __DIR__"w1st2",
                        "north": __DIR__"wn1av1",
                        "south": __DIR__"ws1av1",
            ]));
           set("item_desc",([
"����" : "�վB�����H�B�i�������СA�W���g�ۡG
                    ��
                    �x
                    �x
                    �x
                    �w
                    �R
                    ��
                    ��
                    �j
                    �D
���w�վB��������j��   ���ˤҤj�D�w��
                    ��
                    �A
                    ��
                    �j
                    �D
                    �x
                    �x
                    �x
                    ��
\n",
"�U���D�\\" : "�@���K�s���U���D�\\�A�W�����լ}�ѿn���y�J�U���D�C\n",
"����" : "�b�H��D���䪺�W�ѡA�`���@�`�A�̭��n�F�Ǿ𸭸�U���A
�i�b�U�B���������ɿn���ܤU���D�̡C\n",
                 ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}

