inherit ROOM;
void create()
{
        set("short", "�p��");
        set("long", @LONG
�o�̴N�O�b�Ѧ��U���p�ˡA�ۤѤs���W�L�ۦӤU�A�e���Q�ƤV�A���y
���e�A���礣�`�A���u���@�ؾl�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"l2",
  "south" : __DIR__"l4",
]));
set("item_desc", ([
    "�p��" : "�z�I�o�M�����p�ˡA�̾A�X���ӷ|��a���H�ӽm��(practice)��a�F�C\n",
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        if( this_player()->query_temp("Swim") )
                this_player()->delete_temp("Swim");
        add_action("do_practice","practice");
        add_action("do_go","go");
}
int room_effect(object me)
{
   me=this_player();
   if(me->query_temp("Swim")) 
   {
     if(me->query("swim")>20) return notify_fail("�A���a�ަb�o���L���a��A�w�g�L�k�i�B�F�C\n");
     if(me->query("ap")<10) return notify_fail("�A����O�����F�A�L�k�A�m�ߴ�a�C\n");
     message_vision("$N�b���W�V�O���m�ߴ�a�A���G�ᦳ�߱o�C\n",me);
     me->improve_skill("swim", random(me->query_int()+5)+1);
   }   
}
int do_practice(string arg)
{
        object me;
        me=this_player();
        if(arg != "swim")  return notify_fail("�A�u��b�o�̽m�ߴ�a(swim)�C\n");
        if( me->over_encumbranced() ) return notify_fail("�A���t���L���M�ʼu���o�C\n");
        if( me->query("wound/foot") > 10 ) return notify_fail("�A�����}�˶չL���A�L�k��a�C\n");
        if( me->query("wound/hand") > 10 ) return notify_fail("�A������˶չL���A�L�k��a�C\n");
        if( me->query("wound/head") > 10 ) return notify_fail("�A���Y���˶չL���A�L�k��a�C\n");
        if( me->query("wound/body") > 10 ) return notify_fail("�A������˶չL���A�L�k��a�C\n");
        if(me->query("ap") <10) return notify_fail("�A����O�����A�L�k�~��m�ߴ�a�C\n");
        if( me->query_temp("Swim"))
                return notify_fail("�A�w�g�b�m�ߴ�a�F�C\n");
        if( me->is_fighting() )
                return notify_fail("�A�����ۥ��[�A�S�Žm�ߴ�a�C\n");
        if( me->is_ghost() )
                return notify_fail("�����F�A���D�A�n��Ӥ����`�H�H\n");
        if( me->is_busy() )
                return notify_fail("�A�����ۡA�S���Žm�ߴ�a�C\n");
        if( me->query_skill("swim",1) > 20 )
                return notify_fail("�b�o�ؤ��L�A�A���a�޵L�k�i�B�F�C\n");
        message_vision("$N�`�`�l�F�@�f��A�}�l�m�ߴ�a�F�C\n",me);
        me->set_temp("Swim",1);
        return 1;
}
int do_go(string arg)
{
        object me;
        me=this_player();
        if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
        if(me->query_skill("swim") <20 )
        {
         tell_object(me,"�A����ޤ����¼��A���e�h�N�|���ͩR�M�I�C\n");
        }
        else {
         message_vision("$N�ϥX�¼�����ޡA�w�w�����e��h�C\n",me);
         me->move(__DIR__"l2");
        }
        return 1;
}
