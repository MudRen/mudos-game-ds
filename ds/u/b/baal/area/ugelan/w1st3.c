#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"�վB�����w���ˤҤj�D(The Avenue of Dwarf)"NOR);
        set("long", @LONG
�A�����B��վB�����~�����F��V�D�n�F�D�w���ˤҤj
�D���W�A�D���@��O�վB��������u�ƶ��w(Military of 
Ugelan)����������ҡA�����ҹﭱ�h�O�@�a�W���u��÷���v
(Bla--ck Rope)���p���]�A�@���_�����}�©۵P�a�۶ȳѪ�
�@��÷���������n�\�ۡA�۵P�U�O�@���g���o�áB�ǹЪ���
�l�A�L�z���O���q���̳z�S�X�ӡA�ϧw�̩��ƴ��X�L�z����
�ϬO�o�Ӯ��]�٦b�g�窺�ߤ@��H...
LONG
        );
        set("exits", ([ 
                        "north": __DIR__"ugw1",
                        "south": __DIR__"brinn",
                        "west": __DIR__"w1st2",
            "east": __DIR__"w1st4",
            ]));
           set("item_desc",([
"�U���D�\\" : "�@���K�s���U���D�\\�A�W�����լ}�ѿn���y�J�U���D�C\n",
"�}�©۵P" : "
�۵P�쥻�a���÷���ҦQ���ۡA�{�b�@�ݤw�g�_���A��
�a�ۥt�@�ݤ伵�ۡC\n",
"����" : "�b�H��D���䪺�W�ѡA�`���@�`�A�̭��n�F�Ǿ𸭸�U���A
�i�b�U�B���������ɿn���ܤU���D�̡C\n",
                 ]));
        set("outdoors","land");
        set("light",1);
        set("no_clean_up", 0);
        setup();
}
int do_south()
{
        object me;
        me=this_player();
                return 0;
        message_vision("$N�԰_���b���W����î�A���i�F���]�C \n",me);
        tell_room(environment(me),me->query("name")+"�԰_���b���W����î�A���i�F���]�C\n",me );
        return 1;
}

