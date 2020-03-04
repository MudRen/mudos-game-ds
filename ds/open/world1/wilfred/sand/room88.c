#include <ansi.h>
inherit ROOM;

void can_north(int index);

void create()
{
  set ("short", HIR"�����۪�"NOR);
  set ("long", @LONG
�Ө�o���j���ؿv�~�A�u���o�ؿv�~�ή𬣵ضQ�����A�i��O�Y
��j���v�դ��H����v�C�����ݨ쪺�O�����⪺�j���A�������Q����
�A�e�Q�ءA�㮰���ҥH���C�ۻs���A�Q���Q���I���A�j���O���W���A
�Q�n���}�i��n��@�f�O��C
LONG
);

  set("exits", ([
  "southwest" : __DIR__"room80",
  "southeast" : __DIR__"room84",
]));

  set("item_desc", ([
"�j��" : "\n\t�u�����k�⮰���W���U���@���_�ͤաA���䪺�_�ͤթP���F�����A"+
         "\n\t�k��h�O�Ⱥ��A�]�\\�ӥh��X�A�_�ͪ��Ӹո� (plug left �� plug right)�C\n\n",
]));
  set("no_clean_up", 0);
  set("no_recall",1);
  setup();
}

void init()
{
  add_action("do_plug","plug");
  add_action("do_pray","pray");
}

int do_plug(string str)
{
  object key, me = this_player(), ob = this_object();
  if( str != "left" && str != "right" ) return 0;

  if(me->is_busy()) return notify_fail("�A���b���C\n");
  me->start_busy(2);
  if(str == "left")
  {
    if(!key = present("gold key",me)) return notify_fail("�A�S���X�A���_�ͳ�I\n");
    message_vision(HIW"\n$N�N$n���J�����_�ͤդ�....\n\n"NOR,me,key);
    ob->set("open_left",1);
    call_out("at_same_time",1,key,me);
    return 1;
  }
  if(str == "right")
  {
    if(!key = present("silver key",me)) return notify_fail("�A�S���X�A���_�ͳ�I\n");
    message_vision(HIW"\n$N�N$n���J�Ȧ��_�ͤդ�....\n\n"NOR,me,key);
    ob->set("open_right",1);
    call_out("at_same_time",1,key,me);
    return 1;
  }
  return 1;
}

void at_same_time(object key, object me)
{
  if(!me || environment(me) != this_object())
  {
    tell_room(this_object(),"���G����Ƴ��S�o��.....\n");
    return;
  }

  if(!query("open_left") || !query("open_right"))
  {
    tell_room(this_object(),WHT"�Ať��y�ءz���@�n���T�A���S�o�ͥ���� .....\n"NOR);
    delete("open_left");
    delete("open_right");
    return;
  }

  if(key->query("id") == "silver key")
  {
    destruct(key);
    return;
  }
destruct(key);
  call_out("msg",1,0);
  return;
}

void msg(int index)
{
  string *str = ({
HIG"\n\t�F �I ���}�F ......... �@�I�I���p�_�C\n\n"NOR,
HIG"���٬O�����H���H�q��C\n"NOR,
HIR"\n�ݨӥu�� Plug & Pray �F�A�W�ѫO���C\n\n"NOR,
HIW"�ж}�lë�i(pray)�a.........\n"NOR
});

  tell_room(this_object(),str[index]);
  index++;
  if(index < sizeof(str)) call_out("msg",3,index);
    else set("can_pray",1);
  return;
}

int do_pray()
{
  string *str, msg = "";
  int i, index;
  object env;

  if(!query("can_pray")) return 0;
  if(this_player()->is_busy()) return notify_fail("�A���b���C\n");
  this_player()->start_busy(1);

  str = ({
"�U�઺�W�Ұ�","�t�����R�����S","����Ѫ��M��̦nť�F",
"�򯪫O����","�[�@������","�j�����p��","�ӤU���Ѥ�","���",
"�ڬO��","�ڷQ�Y���S�Y","���]�鶴�餣�n�C","�ڤQ�K���A�ڤ���ϡC",
"�ڤۤC��u�n���A�j�a�@�_���s�i�C",
"�z����!! �z����!! �ڤۤC��u����A�����n�n���Ӫ��C"
});
  index = random(2)+1;
  for(i=0;i<index;i++)
    msg += str[random(sizeof(str))];

  message_vision("$N�@�۪�����D�G " +msg+ "\n",this_player());

  env = load_object(__DIR__"room92");
  if(random(20) == 7)
  {
    delete("can_pray");
    tell_room(this_object(),HIW"�I�����j���ש�}�F ... �V.... �p�ߡI�I�I\n"NOR);
    can_north(1);
    if(!env->is_war()) env->start_war();
      else tell_room(this_object(),"�p�߶^�ˡI�I\n"NOR);
  }
  return 1;
}

void reset()
{
  object env;
  env = load_object(__DIR__"room92");
  if(env->is_war()) return;

  delete("can_pray");
  delete("open_left");
  delete("open_right");
  can_north(0);
  ::reset();
}

void can_north(int index)
{
  string temp;
  mapping exits = query("exits");

  if(!index)
  {
    set("exits", ([
"southwest" : __DIR__"room80",
"southeast" : __DIR__"room84",
]));
    tell_room(this_object(),HIB"\n�۪��S�w�w�����W�F ...... \n\n"NOR);
    return;
  }

  temp = __DIR__"room89";
  if(mapp(exits)) set("exits", (mapping)exits + ([ "north" : temp, ]) );
    else set("exits", ([ "north" : temp, ]));

  tell_room(this_object(),HIW"\n�F�A�u���۪��w�w�����}�F�I�I\n\n"NOR);
  return;
}

/*
int valid_leave(object me, string dir)
{
  if( dir == "north" && !userp(me) && me->query("id") != "ghost") return notify_fail("���̥u�����a�~��i�h�C\n");
  return ::valid_leave(me, dir);
}

*/
