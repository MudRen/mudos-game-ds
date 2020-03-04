#include <ansi.h>
inherit ROOM;

string *str = ({"�b","��","��","�H","��","�[","��","��","��","��","�a","��","�U","��","��","�v"});

string random_item();
void can_down();
void game_change(int index);

void create()
{
  set ("short", "�۫�");
  set ("long", @LONG
�o�O�@�ӤK�ب��誺�۫ǡA�ݨӨõL�ƯS�O���B�A�u���@�����
�W��ۼƭӷ��j���r�G

�@�b �� �� �H �� �[ �� �� �� �� �a �� �U �� �� �v
�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@                  �ФѾ��l
LONG
);

  set("exits", ([
"north" : __DIR__"room48",
]));

  set("item_desc", ([
"�a�O�W���_���ϧ�" : "\n�a�O�W�����e�F�@�ӹ��O�l�^�}�k���ϧΡA��A�IĲ���ɡA�����M�G�F"+
                     "\n�_�ӡA���ϧέY�D��N��M�A�ٯu�ݤ��X�ӡC\n\n",
"���" : (: random_item :),
]));

  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_push","push");
  write("�A���Gť��y����.... �z���@�n ...\n");
}

int do_push(string arg)
{
  int i;
  object obj;

  if(!query_temp("can_push")) return 0;
  if(query_temp("game_now")) return notify_fail("�o�Ǧr�v�L�ݦA���F�C\n");

  for(i=0;i<sizeof(str);i++)
  {
    if(arg != str[i]) continue;
    if(arg != query("item"))
    {
      write("�@�I���R�]�S��...\n");
      return 1;
    }
    if(!obj = present("eight mirror",this_player()))
    {
      write("�A�ϥX�������O��h���o�Ӧr�A�˱o���Y�j���o�L�k�ʨ�@���@�@�A�u�o�o�M�Ӫ�C\n"+
            "�u���r�W���@�Ӭ��ڴx�j�A�K���Ϊ��}�A��������\\�ΡC\n");
      return 1;
    }

    set_temp("in",obj->query("mirror_set_in"));
    set_temp("out",obj->query("mirror_set_out"));
    message_vision(HIW"\n$N�N$n�O�b�}�W�A�����@���A�i"+query("item")+"�j�r���n�ӤJ�A���ۥ۫Ǭ�M�@�}�@�P�n�ʡA�L���[�S�^�_���R�C\n\n"NOR,this_player(),obj);
    destruct(obj);

    call_out("eight_mirror",5);
    return 1;
  }
  write("�A�n������H\n");
  return 1;
}

string random_item()
{
  string temp = "";
  mapping item = query("item_desc");
  int index, i;

  write(HIR"\n���F����W�誺�o�Ǧr�A��L�a��A�]�S���ƯS�O���B�A���D�o�Ǧr.... �H\n\n"NOR);

  if(query_temp("can_push")) return "";

  index = random(12);
  for(i=0;i<sizeof(str);i++)
  {
    if(i==index)
    {
      set("item",str[i]);
      temp += NOR+WHT+str[i]+NOR+" ";
    }
    else temp += HIW+str[i]+NOR+" ";
  }

  if(mapp(item)) set("item_desc", (mapping)item + ([ "�r" : temp+ "\n\n�o�Ǧr�ݨӦ��ǥj�ǡA���G�i�H��(push)�U�h�H\n", ]) );
    else set("item_desc",([ "�r" : temp+ "\n\n�o�Ǧr�ݨӦ��ǥj�ǡA���G�i�H��(push)�U�h�H\n", ]) );

  set_temp("can_push",1);

  return "";
}

void reset()
{
  object env;
  env = load_object(__DIR__"room92");
  if(env->is_war()) return;

  if(query_temp("game_now")) return;

  tell_room(this_object(),HIC"\n�}�S�C�C�����F�_�� ......\n\n"NOR);
  set("exits", ([
"north" : __DIR__"room48",
]));

  set("item_desc", ([
"�a�O�W���_���ϧ�" : "�a�O�W�����e�F�@�ӹ��O�}�k���ϧΡA��A�IĲ���ɡA�����M\n�G�F�_�ӡA���ϧέY�D��N��M�A�ٯu�ݤ��X�ӡC\n",
"���" : (: random_item :),
]));

  delete_temp("can_push");
  ::reset();
}

void eight_mirror()
{
  can_down();
/*
  game_change(0);
  tell_room(this_object(),HIR"\n�u���@�ӥ۬W�q�a�O�W���_���ϧΤ����ɤF�_�ӡI�I\n\n"NOR);
  stone = new(__DIR__"npc/obj/obj23");
  stone->move(this_object());
  stone->accept_
*/
  game_change(1);     // ����۬W�g�n�n�R��, �W���n��^��
  return;
}

void can_down()
{
  string temp;
  mapping exits = query("exits");

  temp = __DIR__"room" + ( (string)random(4)+70 );
  if(mapp(exits)) set("exits", (mapping)exits + ([ "down" : temp, ]) );
    else set("exits", ([ "down" : temp, ]));

  tell_room(this_object(),HIR"\n�a�O�W�e���_���ϧά�M���F�@�Ӥj�}�I�I\n\n"NOR);
  return;
}

void game_change(int index)
{
  object white, black, room;
  int i;
  if(!index)
  {
    set_temp("game_now",1);
    return;
  }

  delete_temp("game_now");
  tell_room(this_object(),HIG"\n�a�������B�ǨӤ@���n�T�C\n\n"NOR);

  white = load_object(__DIR__"room69");
  black = load_object(__DIR__"room67");
  white->can_down(1);
  black->can_down(1);

  // �H�U�o�ǵ{���X�b�۬W�g�n����n�R��
  // -----------------------------------------
  for(i=50;i<66;i++)
  {
    room = load_object(__DIR__"room"+i);
    room->change(random(8)+1);
  }
  // -----------------------------------------

  return;
}

