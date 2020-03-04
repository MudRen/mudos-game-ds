inherit ROOM;
void create()
{
        set("short","�j��W");
        set("long",@LONG
�A�Ө�F���K�����ݡA�o�̬ݨӤw�g�S������F�A���a�]����䪺���K
���F���֡A���W�i�H�ݨ���諸�ѪšA���U�h�i�H�M���������U���j��L
�A�ӧA�]�`�N����䦳�ۤ@�ʥ��j���j��A�ӥB���q�L��A���G�i�H�٬��o
�̪�����]�����L�C
LONG
        );
        set("exits", ([
  "south" : __DIR__"stn6",
]));
        set("no_clean_up", 0);
        set("light",0);
        set("item_desc", ([
            "�j��L" : "�ܦh���j��h�h�����A�Φ��F�᧧�[���j��L�A�j��L�������@�Ӥp�Ŧa�H\n",
            "�Ŧa" : "�j��L�����@�ӪŦa�A�ݨӻᬰ��a�A�����a���q�Z���A�i��n�Q��k�q�L(jump_to)�C\n",            
            "�Ѫ�" : "�ܼs�諸�@���ѪšA���M�P�򦳥j��B���A���O�o�̪������o�ܲM���C\n",
            "���j�j��" : "�@�ʤQ�����j���j��A�Pı�N�O�j�줤�����A�i�H���W�h�ݬݡH(jump_to)\n",            
         ]));   
        setup();
}


void init()
{
 add_action("do_jump","jump_to");
}

int do_jump(string arg)
{
  object me,ob = this_object();
  string msg;
  int rets;
  me=this_player();
  if(!arg ) return notify_fail("�A�n������� ?\n");
  if(me->is_busy() || me->is_fighting() )  return notify_fail("�A���b��\n");
  if(arg=="�Ŧa" || arg=="���j�j��")
  {
   msg="$N�ĤO���Ť��@�D�Ӱ_";
   if(me->query_skill("force",1)<60) msg+="�A���O���O�������~�ӱ��F�U�h�C\n";
   else if(me->query_skill("force",1) < 80 ) msg+="�A$N���߶ʹB���\\�A�i�O��ߦR�ɦӵL�O���F�U�h�C\n";
   else if(me->query_skill("force",1) < 100 ) msg+="�A$N�N���\\�@�f�𴣦ܤ��СA�o�٬O�L�k���\\�D�W�C\n";
   else if(me->query_skill("force",1) == 100 ) msg+="�A$N�N���\\�B�ܳ��p�A�i���Ȯt�X�`�ӷƸ��L�U�C\n"; 
   message_vision(msg,me);
   rets = me->query_skill("force",1)/20;
   me->receive_wound("left_leg",60/rets);
   me->receive_wound("right_leg",60/rets);
   me->receive_wound("left_arm",60/rets);
   me->receive_wound("right_arm",60/rets);
   me->receive_wound("head",60/rets);
   me->receive_wound("body",60/rets);             
   me->receive_damage("hp",me->query("hp")*1/(rets+1));
   me->start_busy(1);
   me->move(__DIR__"t18.c");
   tell_room(environment(me), "�y���@�n�A"+me->name()+"�q�j�챼�F�U�ӡA�ݨӨ��ˤ��L�I\n", ({ me }));
  }
  else if(arg=="bird")
  {
   if(!ob->query("can_jump_bird")) return notify_fail("�A�n������� ?\n");
   msg="$N�B�_���\\�������ӥh";
   if(me->query_skill("dodge",1)<60) msg+="�A���O���\\�y�ڤ����ӱ��F�U�h�C\n";
   else if(me->query_skill("force",1) < 70 ) msg+="�A$N�D�ܭ����W�A�i�O���\\�����ɤO�A�ӤO�ɸ��U�C\n";
   else msg+="�A$N���ܭ����W�ɤO�ӤW�b�šA�Ŧa�N�b�U�褣���B�C\n";
   message_vision(msg,me);
   if(me->query_skill("force",1) >= 70)
   {
        me->move(__DIR__"stsky");
        me->start_busy(4);
        tell_room(environment(me), "�H�v�@�{�A"+me->name()+"�q�U��w�w�ɰ_�A���\\�X���J�ơI\n", ({ me }));
   } 
   else{
        me->receive_wound("left_leg",10+random(15));
        me->receive_wound("right_leg",10+random(15));
        me->receive_wound("left_arm",10+random(15));
        me->receive_wound("right_arm",10+random(15));
        me->receive_wound("head",10+random(15));
        me->receive_wound("body",10+random(15));             
        me->receive_damage("hp",me->query("hp")*1/3);
        me->start_busy(1);
        me->move(__DIR__"t18.c");
        tell_room(environment(me), "�y���@�n�A"+me->name()+"�q�j�챼�F�U�ӡA�ݨӨ��ˤ��L�I\n", ({ me }));       }    
  }
  else return notify_fail("�A�n������� ?\n"); 
  return 1;
}

void can_jump()
{
        set("item_desc", ([
            "�Ѫ�" : "�ܼs�諸�@���ѪšA�ѪŤW���@����j�������A�]�\\�i�H�V�e�ɤO���Ť�?(jump_to)�C\n",
         ]));
        set("can_jump_up",1);
        call_out("delele_jump",180);       
        return;
}


void delete_jump()
{
        set("item_desc", ([
        "�Ѫ�" : "�ܼs�諸�@���ѪšA���M�P�򦳥j��B���A���O�o�̪������o�ܲM���C\n",            
        ]));
        delete("can_jump_up");       
        tell_room("�ѪŤW�������b�L�ۤF�\\�[����A���ѫ�S�ӥh�F\n");        
        return;
}
















