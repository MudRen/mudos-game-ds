
inherit ROOM;
void create()
{
        set("short", "�L���p��");
        set("long", @LONG
�L���p������o�̡A������������j���Ǧ���Y�A�n�O���������ӫ�
�A�ܦ��i��N�Q�o�����Y�խˤ]�����w�C
LONG
);
        set("exits",([
        "south" : __DIR__"map_2_3",
        "east" : __DIR__"map_1_4",
        ]));
        set("detail",([
        "���Y" : "�A�`�N����Y�U���G���ۤ@���զ⪺���H�I\n",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        add_action("do_search","search");
}
int have_eq=1;
void reset()
{
        have_eq=1;
        ::reset();
}

int do_search(string arg)
{
        object me=this_player(),eq;
        if(!arg || arg!="���Y") return 0;
        if(have_eq==1)
        {
                eq=new(__DIR__"npc/obj/gloves.c");
                eq->move(me);           
                message_vision("$N������h�}�F�j���Y�A���G�o�{�@�����b���Y�U����M�C\n",me);
                have_eq=0;
        }
        else {
                message_vision("$N�������|�_�F�j���Y�A�@���b���䪺���O�̡C\n",me);
        }
        return 1;
}
