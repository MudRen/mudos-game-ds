// Room: /tmr/garea/tree_up.c

inherit ROOM;

void do_clear() {
        if(this_object()) return;
        delete_temp("quest");
}

void create()
{
        set("short", "��K�W");
        set("long", @LONG
�A�����ۤ@�ڻᬰ�ʤj����K�W�A�W���c�����񸭻\���A�������ǥ�
�u�z�U�ӡA�A���������@���b��K���ݦ��Ӥj���_�A�ֻ��]���@�볾�_��
�ƤQ���j�C
LONG
        );
        set("no_clean_up", 0);
        set("item_desc",([
        "���_":"�_���Y���G���X���j�Y�H�Y�������W���J�C\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "down" : __DIR__"forest5",
        ]));
        set("objects",([
        __DIR__"npc/chisel":2,
        ]) );
        set("outdoors","forest");
        setup();
}
void init()
{
          add_action("do_search","search");
}

int do_search(string arg)
{
        object egg,me;
        me=this_player();
        if(!arg || arg!="���_") return 0;
        if ( !query_temp("quest") ) 
        {
                message_vision("$N�q���_���j�X�F�@���զ⪺�j��y�C\n",me);
                set_temp("quest",1);
                egg=new(__DIR__"npc/obj/egg");
                egg->move(me);
                 call_out("do_clear", 600);     // 10����

        } else
                message_vision("$N�b���_���j�F�j�A���G�S���o�{�줰��...\n",me);
        return 1;
}

