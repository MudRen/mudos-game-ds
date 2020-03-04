// Room: /open/world1/manto/sky2_1f/map_7_1.c

inherit ROOM;

void create()
{
	set("short", "�e�t");
	set("long", @LONG

    �ݨ�o�̤���M���A���A�Q��Ө��������U�h��a(practice swim)�C
LONG
	);
	set("light", 1);
	set("ourdoors", "land");
	set("current_light", 1);
	set("map_long", 1);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"map_7_3",
]));
	set("no_clean_up", 0);
        set("objects",([
  __DIR__"npc/goldman7" :9,
    __DIR__"npc/goldman6" :1,
]));

	setup();
}

void init()
{
        if( this_player()->query_temp("Swim") )
                this_player()->delete_temp("Swim");
        add_action("do_practice","practice");
}

int room_effect(object me)
{
   me=this_player();
   if(me->query_temp("Swim")) 
   {
     if(me->query("swim")>99) return notify_fail("�A���a�ަb�o���L���a��A�w�g�L�k�i�B�F�C\n");
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
        if( me->query_skill("swim",1)<40)
        return notify_fail("�A���a�ޤ����¼��A�b�������B���I��T�V�����a���F�W�ӡC\n");
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
        if( me->query_skill("swim",1) > 99 )
                return notify_fail("�b�o�ؤ��L�A�A���a�޵L�k�i�B�F�C\n");
        message_vision("$N�`�`�l�F�@�f��A�}�l�m�ߴ�a�F�C\n",me);
        me->set_temp("Swim",1);
        return 1;
}     
