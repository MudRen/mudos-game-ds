// xiaolu8.c ��s�p��
// xiaolu8.c ��s�p��

inherit ROOM;
string l_pattern();

void create()
{
        set("short", "��s�p��");
        set("long", @LONG
�o�̬O��s�W���p���C�o���p���n�����O�H�u��N�ץX�Ӫ��A
�]�\�u�O�H�e�����ĤH��h�F�A�{�X�o�ˤ@���p���ӡC�s���W�n��
��ۤ@�Ǥ���r��(pattern)�C����o�̡A�A�n���g���F�C
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"xiaolu7",
                "north" : __DIR__"xiaolu4",
                "south" : __FILE__,
        ]));
        set("item_desc",([
          "pattern" : (:l_pattern():),
        ]));
        set("no_clean_up", 0);

	set("coor/x", -2680);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        //replace_program(ROOM);
}

string l_pattern()
{
        object me=this_player();
        if(me->query_temp("tmark/��")==1) {
                me->add_temp("tmark/��",1);
                return("�n���O�Q�H�Τj�O������O�������\�Ҧb�s�ۤW��U�@���֡A�o
�H�����O�i�u�F�o�C\n");
        }
        else {
                me->set_temp("tmark/��",1);
                return("�s���W��ۤ@���֡A�����D�O����W�h���C\n");
        }
}