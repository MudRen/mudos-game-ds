// �� 30 �ئW���ܤƪ���   wilfred@DS
inherit NPC;

void change();
void do_move(object me, object ob, object target);
string font(string str);

void create()
{
  set_name("����",({"cow"}) );
  set("race","beast");
  set("unit","��");
  set("age",random(4)+1);
  set("level",random(30)+1);
  set("con",query("level")*3/2);
  set("str",query("level")*3/2);
  set("limbs", ({ "�Y��","����","�ݳ�","����","����","����" }) );
  set("verbs", ({ "bite","claw" }) );
  set("chat_chance",8);
  set("chat_msg", ({
(: random_move :),
}) );

  setup();
}

void init()
{
  add_action("do_pull","pull");
  if(query("new_ob")) return;
  set("new_ob",1);
  change();
}

void change()
{
  int index = query("level");
  string *str_c = ({
" ",
"�p","��","��","�ť�","�t��","��","�A��","����","�ů�","����",
"�j","����","�ᴳ","���B","�`�s","�z�_","���","�٫n","ή�_","����",
"��","�d�h","�դh","�C�P","�ժ�","�x��","�u��","�l��","�ƨR","�ⶳ",
// "���Z��","�괭","���w","�V��","�Y��","���F","����","�N�x","��s","[���դh�S���~��]�ץ�"
});

string *str_e = ({
" ",
"small","younger","young","white","brown","yellow","red","fire","blue","water-blue",
"big","golden","flower","transmission","mountain","north","green","south","city-north","war",
"water","water-hole","doctor","mild-seven","white-long","hung-yea","chung-fan","wd","uao-chung","cloud",
// "w-k-d-s-f","city-power","chung-dhea","clouder","stone","east","west","leader","mountain-digger","meat"
});

  set_name(str_c[index]+"����",({str_e[index]+" cow","cow"}));
  set("long","�o�O�@��"+chinese_number(query("level"))+"�Ū�"+query("name")+"�C\n");
  return;
}

int do_pull(string str)
{
  object me = this_player(), ob = this_object();
  object env = environment(me), target, rope;
  mapping exit = env->query("exits");

  if(!env) return notify_fail("�|�B�@���·t�A�A�L�k��ʡC\n");
  if(!rope = present("rope",me)) return notify_fail("�A�ݭn�@��÷�l�өԤ��C\n");
  if(me->is_busy()) return notify_fail("�A���b��.\n");
  if(!str) return notify_fail("�A�n����Ԩ���Ӥ�V�S\n");
  if(undefinedp(exit[str])) return notify_fail("�A�������Ԩ�o�Ӥ�V�C\n");
  if( !target = find_object(exit[str]) ) return notify_fail("�A�o�{�Ʊ����j��F�A���S�����W�ӡA�̦n���ֳq���Ův�C\n");

  message_vision("$N���X"+rope->query("name")+"�ϫl���Ե�"+ob->name(1)+"��"+font(str)+"���h�C\n",me);
  call_out("do_move",2,me,ob,target);
  return 1;
}

void do_move(object me, object ob, object target)
{
  if(!ob->move(target)) return;
  if(!me->move(target)) return;
  tell_object(me,"�A�O�F�E���G�ꤧ�O�~�N���Ԩӳo�̡A�u���A�v�ֱo��ݦS�S�A�w�b�a�W�F�C\n");
  tell_room(target,me->name(1)+"�Եۤ@�Y"+ob->name(1)+"�Ө즹�a�C\n",me);
  me->add_busy(2);
  return;
}

string font(string str)
{
  string msg;
  switch(str)
  {
    case "east"      : msg = "�F��"; break;
    case "west"      : msg = "����"; break;
    case "north"     : msg = "�_��"; break;
    case "south"     : msg = "�n��"; break;
    case "northeast" : msg = "�F�_"; break;
    case "northwest" : msg = "��_"; break;
    case "southeast" : msg = "�F�n"; break;
    case "southwest" : msg = "��n"; break;
    case "up"        : msg = "�W";   break;
    case "down"      : msg = "�U";   break;
    case "enter"     : msg = "��";   break;
    case "out"       : msg = "�~";   break;
  }
  return msg;
}

