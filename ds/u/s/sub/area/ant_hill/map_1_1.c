inherit ROOM;
void create()
{
	set("short", "�q�D");
        set("long", @LONG
                �a�W���@�Ӥp�p���|�}�C
LONG
);
	set("exits",([
	"south" : __DIR__"map_2_1",
	"east" : __DIR__"map_1_2",
	]));
        setup();
        set("map_long",1);     //show map as long
        set("item_desc",([
        "�p�|�}":"�@�Ӥp�p���}�A���@�ǶäC�K�V���F��b�̭��C\n",
        ]) );
}

void init()
{
        add_action("do_search","search");
}

int i= 1;

int do_search(string arg)
{
        object me,head;
        head=new(__DIR__"npc/obj/cateye");      
        if( !arg || arg!="�p�|�}" ) return 0;
        me=this_player();
         if( i==1 )
        {
        message_vision("$N���F���a�W���|�}�A���X�F�@���G�G���F��C\n",me);
        head->move(environment(me) );
        i=0;
        }
        else
        {
        message_vision("$N���F���a�W���|�}�A���X�F�@�j�諸�U���A�o�S��줰��ȿ����F��C\n",me);
        }               
        return 1;
}
