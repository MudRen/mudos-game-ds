inherit ROOM;

void create()
{
        set("short", "���H�P�}");
        set("long", @LONG 
�o�̪����[�A�b�o�̧󦨤@��A�Ҧ����F�賣�\�W�F�զ⪺�F
�l�A�@�����ժ�����A�b�A�ߤ��L�U�����n���L�H�A�B�����٦���
�@���j���y���Y�z�A�����D�O������Ϊ��C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room7", 
  "north" : __DIR__"room9",
]));
        set("light",1);
set("item_desc",([
"���Y":"�����e�����n���o������ۡA���G�i�H�h�}[take]���ˤl�A�i�O�Pı�������I�H\n",
]) );

        set("no_clean_up", 0);

        setup();
}
void init() 
{
        add_action("do_take","take");
}


int do_take(string arg)
{
        object me,x;
        x=new(__DIR__"npc/obj/paper");      
        if( !arg || arg!="���Y" ) return 0;
        me=this_player();
         if( me->query("level") > 39  )
        {
        message_vision("$N�ϤO�h�}���ۡA�@���@�i���֯ȡC\n",me);
        x->move(environment(me) ); 
        }
        else
        {
        message_vision("$N�ϤO�h�}���ۡA���G����]�S���o�{�C\n",me);
        }               
        return 1; 

        call_out("reborn", 900);
}

