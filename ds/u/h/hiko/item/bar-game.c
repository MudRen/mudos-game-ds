//���Q��v1.0
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("�Ův��BAR��" ,({ "wiz Bar","Bar","bar","b","w"}) );
        set_weight(9000);
        set("no_get",1);
        set("no_sac",1);
        set("value",5);
        set("long", @LONG
�A�������]�w���Q���w�X(bet)�A
�M��N�i�H�γo�x�����Ӫ����Q(bar)�F�I
LONG );
        set("unit", "�x");
        set("bet", 5);
}

void init()
{
        add_action("go_bar", "bar");
        add_action("go_bet", "bet");
        add_action("go_look", "look");
}

int go_bar(string what)
{
  object money,me;
  me=this_player();
  money=present("coin",me);

if(money && money->query_amount() > this_object()->query("bet")) {
if(this_object()->query_temp("bar_now"))
        return notify_fail("�������b�B�त�A�еy��.....\n");
message_vision("$N�\\�X�@�ӫܻ�POSE�ԤU�Q��A����}�l���.....\n",this_player());
this_object()->set_temp("bar_now",1);
money->add_amount(-this_object()->query("bet"));
call_out("labar",3,this_object());
        }
else
        return notify_fail("�A����������U�ثe����`\n");

return 1;
}

int labar(object ob)
{
string pic1,pic2,pic3;
object money,me;
int lucky = random(6);
int lucky2 = random(6);
int lucky3 = random(6);
int luck1,luck2,luck3;

if(lucky == 3 || lucky == 5)
 {  
   if(lucky==lucky3)
     {
      lucky2=lucky;
     }
     else
      {
       if(lucky==lucky2)
        lucky3=lucky;
      }
 } 
  me=this_player();
  money=present("coin",me);
this_object()->delete_temp("bar_now");
if(lucky == 1) {
pic1 = "�x�z�w�w�w�{�x
�x�x"HIR"������"NOR"�x�x
�x�x "HIG"�Ԣ� "NOR"�x�x
�x�x"HIR"������"NOR"�x�x
�x�|�w�w�w�}�x";
luck1 = 7;
} else if(lucky == 2) {
pic1 = "�x�z�w�w�w�{�x
�x�x"HIY"�f�f�f"NOR"�x�x
�x�x�@"HIY"����"NOR"�x�x
�x�x�@"HIY"�p"NOR"�@�x�x
�x�|�w�w�w�}�x";
luck1 = 2;
} else if(lucky == 3) {
pic1 = "�x�z�w�w�w�{�x
�x�x"HIG"���p��"NOR"�x�x
�x�x"HIG"�p�@�p"NOR"�x�x
�x�x"HIG"���p��"NOR"�x�x
�x�|�w�w�w�}�x";
luck1 = 3;
} else if(lucky == 4) {
pic1 = "�x�z�w�w�w�{�x
�x�x"HIR"������"NOR"�x�x
�x�x"HIY"�ТϢ�"NOR"�x�x
�x�x"HIR"������"NOR"�x�x
�x�|�w�w�w�}�x";
luck1 = 4;
} else if(lucky == 5) {
pic1 = "�x�z�w�w�w�{�x
�x�x"HIY"�@���@"NOR"�x�x
�x�x"HIY"������"NOR"�x�x
�x�x "HIY"���� "NOR"�x�x
�x�|�w�w�w�}�x";
luck1 = 5;
} else {
pic1 = "�x�z�w�w�w�{�x
�x�x"HIC"���p��"NOR"�x�x
�x�x"HIC"�p"HIW"��"HIC"�p"NOR"�x�x
�x�x"HIC"���p��"NOR"�x�x
�x�|�w�w�w�}�x";
luck1 = 6;
}

if(lucky2 == 1) {
pic2 = "�x�z�w�w�w�{�x
�x�x"HIR"������"NOR"�x�x
�x�x "HIG"�Ԣ� "NOR"�x�x
�x�x"HIR"������"NOR"�x�x
�x�|�w�w�w�}�x";
luck2 = 7;
} else if(lucky2 == 2) {
pic2 = "�x�z�w�w�w�{�x
�x�x"HIY"�f�f�f"NOR"�x�x
�x�x�@"HIY"����"NOR"�x�x
�x�x�@"HIY"�p"NOR"�@�x�x
�x�|�w�w�w�}�x";
luck2 = 2;
} else if(lucky2 == 3) {
pic2 = "�x�z�w�w�w�{�x
�x�x"HIG"���p��"NOR"�x�x
�x�x"HIG"�p�@�p"NOR"�x�x
�x�x"HIG"���p��"NOR"�x�x
�x�|�w�w�w�}�x";
luck2 = 3;
} else if(lucky2 == 4) {
pic2 = "�x�z�w�w�w�{�x
�x�x"HIR"������"NOR"�x�x
�x�x"HIY"�ТϢ�"NOR"�x�x
�x�x"HIR"������"NOR"�x�x
�x�|�w�w�w�}�x";
luck2 = 4;
} else if(lucky2 == 5) {
pic2 = "�x�z�w�w�w�{�x
�x�x"HIY"�@���@"NOR"�x�x
�x�x"HIY"������"NOR"�x�x
�x�x "HIY"���� "NOR"�x�x
�x�|�w�w�w�}�x";
luck2 = 5;
} else {
pic2 = "�x�z�w�w�w�{�x
�x�x"HIC"���p��"NOR"�x�x
�x�x"HIC"�p"HIW"��"HIC"�p"NOR"�x�x
�x�x"HIC"���p��"NOR"�x�x
�x�|�w�w�w�}�x";
luck2 = 6;
}

if(lucky3 == 1) {
pic3 = "�x�z�w�w�w�{�x
�x�x"HIR"������"NOR"�x�x
�x�x "HIG"�Ԣ� "NOR"�x�x
�x�x"HIR"������"NOR"�x�x
�x�|�w�w�w�}�x";
luck3 = 7;
} else if(lucky3 == 2) {
pic3 = "�x�z�w�w�w�{�x
�x�x"HIY"�f�f�f"NOR"�x�x
�x�x�@"HIY"����"NOR"�x�x
�x�x�@"HIY"�p"NOR"�@�x�x
�x�|�w�w�w�}�x";
luck3 = 2;
} else if(lucky3 == 3) {
pic3 = "�x�z�w�w�w�{�x
�x�x"HIG"���p��"NOR"�x�x
�x�x"HIG"�p�@�p"NOR"�x�x
�x�x"HIG"���p��"NOR"�x�x
�x�|�w�w�w�}�x";
luck3 = 3;
} else if(lucky3 == 4) {
pic3 = "�x�z�w�w�w�{�x
�x�x"HIR"������"NOR"�x�x
�x�x"HIY"�ТϢ�"NOR"�x�x
�x�x"HIR"������"NOR"�x�x
�x�|�w�w�w�}�x";
luck3 = 4;
} else if(lucky3 == 5) {
pic3 = "�x�z�w�w�w�{�x
�x�x"HIY"�@���@"NOR"�x�x
�x�x"HIY"������"NOR"�x�x
�x�x "HIY"���� "NOR"�x�x
�x�|�w�w�w�}�x";
luck3 = 5;
} else {
pic3 = "�x�z�w�w�w�{�x
�x�x"HIC"���p��"NOR"�x�x
�x�x"HIC"�p"HIW"��"HIC"�p"NOR"�x�x
�x�x"HIC"���p��"NOR"�x�x
�x�|�w�w�w�}�x";
luck3 = 6;
}

write("\n�z�w�w�w�w�w�{\n"+pic1+"\n�u�w�w�w�w�w�t\n"+pic2+"\n�u�w�w�w�w�w�t\n"+pic3+"\n�|�w�w�w�w�w�}\n");

if((luck1 == 7 && luck2 ==7&& luck3 == 7) || (luck1 == 2 && luck2 == 2&& luck3 == 2) || (luck1 == 3 && luck2 ==3&& luck3 == 3) || (luck1 == 4 && luck2==4&& luck3 == 4) || (luck1 == 5 && luck2 ==5&& luck3 == 5) || (luck1 == 6 && luck2 ==6&& luck3 == 6))
        message_vision("���ߡA$P���\\�F�ԥX�T�s�u�I....\n",this_player());
else
        message_vision("�u�r~$P�S�����\\�A�u�i���A�A���@���a�I\n",this_player());
if(luck1 == 7 && luck2 == 7 && luck3 == 7)
money->add_amount(this_object()->query("bet") * 10);
else if(luck1 == 2 && luck2 == 2 && luck3 == 2)
money->add_amount(this_object()->query("bet") * 7);
else if(luck1 == 3 && luck2 == 3 && luck3 == 3)
money->add_amount(this_object()->query("bet") * 5);
else if(luck1 == 4 && luck2 == 4 && luck3 == 4)
money->add_amount(this_object()->query("bet") * 8);
else if(luck1 == 5 && luck2 == 5 && luck3 == 5)
money->add_amount(this_object()->query("bet") * 6);
else if(luck1 == 6 && luck2 == 6 && luck3 == 6)
money->add_amount(this_object()->query("bet") * (random(5) + 5));
}

int go_bet(string what)
{
if(!what)
        return notify_fail("�A�i�H�U�`�����B�G5 coin,10 coin,50 coin,100 coin\n");
if(what != "5" && what != "10" && what != "50" && what != "100")
        return notify_fail("�A�i�H�U�`�����B�G5 coin,10 coin,50 coin,100 coin\n");
if(what == "5")
this_object()->set("bet",5);
else if(what == "10")
this_object()->set("bet",10);
else if(what == "50")
this_object()->set("bet",50);
else if(what == "100")
this_object()->set("bet",100);
write("OK�I�A�N�U�`���B�]�w�� "HIY+what+NOR" �j��\n");
return 1;
}

int go_look(string what)
{
if(id(what)) {
write("
�@�x�j�a���ռ���Ԫ����Q�����A
�W���{�{�ۤ��m�}�ɪ��O�i�O�A�Q�������A
���Q���W�K�ۤ@�i����(note)�A�A�i�H�ݬݡC

�ثe���Q������`�O�C�� "+HIY+this_object()->query("bet")+NOR+" �ӻɹ�
");
return 1;
} else if(what == "note") {
write("
���k�G
�A�������]�w���Q���w�X(bet)�A
�M��N�i�H�γo�x�����Ӫ����Q(bar)�F�I

�U�عϮת����ơG
�z�w�w�w�{    �z�w�w�w�{    �z�w�w�w�{ 
�x"HIR"������"NOR"�x    �x"HIY"�f�f�f"NOR"�x    �x"HIG"���p��"NOR"�x
�x "HIG"�Ԣ� "NOR"�x    �x�@"HIY"����"NOR"�x    �x"HIG"�p�@�p"NOR"�x
�x"HIR"������"NOR"�x    �x�@"HIY"�p"NOR"�@�x    �x"HIG"���p��"NOR"�x
�|�w�w�w�}    �|�w�w�w�}    �|�w�w�w�}
   �Ԣ�           ��           Coin
  ��` *10      ��` * 7      ��` * 5

�z�w�w�w�{    �z�w�w�w�{    �z�w�w�w�{ 
�x"HIR"������"NOR"�x    �x"HIY"�@���@"NOR"�x    �x"HIC"���p��"NOR"�x
�x"HIY"�ТϢ�"NOR"�x    �x"HIY"������"NOR"�x    �x"HIC"�p"HIW"��"HIC"�p"NOR"�x
�x"HIR"������"NOR"�x    �x "HIY"���� "NOR"�x    �x"HIC"���p��"NOR"�x
�|�w�w�w�}    �|�w�w�w�}    �|�w�w�w�}
  �ТϢ�        ���B�P        ��������
  ��` * 8      ��` * 6      ���@�w
\n");
return 1;
} else
return 0;
}




