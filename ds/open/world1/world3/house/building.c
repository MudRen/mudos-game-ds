#include <ansi.h>
inherit HOUSE;
void create()
{
        set_name("�ؿv��", ({"building" }) );
        set_short("�ؿv��","���m���j��");
        set_long(@OUTLONG
�@�ɫܴ��q�Ӹ��Y�ſ������ؿv���A�A�i�H�N�����(rebuild)�C
�A�]�i�H�N���}�a(ruin)�A�]��i�J(enter)�o�ؿv���J�C

OUTLONG
,@INLONG
�o�̪Ūſ������Q���e���A�@�Ӭ۷��q���ؿv���C
INLONG
); // ���ԭz
        set_weight(999999);
        set("light",1);
        set("no_clean_up",1);
        setup();
}
void init()
{ 
         add_action("do_rebuild","rebuild");
         add_action("do_about","about");
         add_action("do_ruin","ruin");
}
int do_rebuild(string arg)
{
    string list;
    object me,obj;
    me=this_player();
    obj=this_object();
    if(obj->query("makenow") >0 ) return notify_fail("�o�ɫؿv�����b��ؤ��C\n");

    switch(arg) {
      case "1":    //��������.
          message_vision("$N�M�w�N�o�ɫؿv����ئ��������ߡC\n",me);
          obj->set("makenow",1);
          obj->set("makename","��������");
          call_out("make",2,arg);
          break;
      case "2":    //�x��.
          message_vision("$N�M�w�N�o�ɫؿv����ئ��x��C\n",me);
          obj->set("makenow",2);
          obj->set("makename","�x��");
          call_out("make",2,arg);
          tell_object(me,"�غc��.....\n");
          break;
      case "3":    //�L�u�t.
          tell_object(me,"�غc��.....\n");
          break;
      case "4":    //�˥Ҭ�o��.
          tell_object(me,"�غc��.....\n");
          break;
      case "5":    //�u�t.
          tell_object(me,"�غc��.....\n");
          break;
      case "6":    //��s�|.
          tell_object(me,"�غc��.....\n");
          break;
      case "7":    //�ɵ���.
          tell_object(me,"�غc��.....\n");
          break;
      case "8":    //�Ӫů�.
          tell_object(me,"�غc��.....\n");
          break;
      default:
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                        �ؿv������:                       ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�ޢw�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��1.  ��������(Command Center)��2.  �x��(Barracks)          ��\n";
          list += "��3.  �L�u�t(Armory)          ��4.  �˥Ҭ�o��(Armor place) ��\n";
          list += "��5.  �u�t(Factory)           ��6.  ��s��(Academy)         ��\n";
          list += "��7.  �ɵ���(Supply Depot)    ��8.  �Ӫů�(Starport)        ��\n";
          list += "��������������������������������������������������������������\n";
          list += "���Y�ݭn��ؿ�J�G  rebuild <�N��> �Y�i�C                   ��\n";
          list += "���Y���i�@�B�o���ؿv���\\�ο�J�G about <�N��> �Y�i�C        ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      }
    return 1;
}
int do_ruin(string arg)
{
        object me;
        me=this_player();
        if(arg != "building" ) return notify_fail("�S���o�تF��@�C\n");
        message_vision("$N�N�o�ɫؿv�����F�C\n",me);
        destruct(this_object());
        return 1;
}
int make(int arg)
{
        object obj,nnew,me;
        obj=this_object();
        me=this_player();
        if(obj->query("right") <= 100 )
        {
          obj->add("right", 2+random(10) );
          obj->set_short("��ئ�"+HIW+obj->query("makename")+HIR"(�����סG"+obj->query("right")+"%)"NOR"  �ؿv��","���m���j��" );
          call_out("make",3,arg);
        }
        else {
          switch( arg ) {
          case "1":    //��������.
             message_vision(HIW"    �������ߤw�سy�����C\n"NOR,me);
             nnew=new(__DIR__"no1");
             nnew->move(environment(obj));
             break;
          case "2":    //�x��.
             message_vision(HIW"    �x��w�سy�����C\n"NOR,me);
             nnew=new(__DIR__"no2");
             nnew->move(environment(obj));
             break;
          case "3":    //�L�u�t.
             break;
          case "4":    //�˥Ҭ�o��.
             break;
          case "5":    //�u�t.
             break;
          case "6":    //��s�|.
             break;
          case "7":    //�ɵ���.
             break;
          case "8":    //�Ӫů�.
             break;
          }
          destruct(this_object());
        }
       return 1;
}
int do_about(string arg)
{
    string list;
    object me;
    me=this_player();
    switch(arg) {
      case "1":    //��������.
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��               ��������(Command Center)                   ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    �������߯��s�U�����Ͳ��Τu��A���F�o�Ǥu��~��i    ��\n";
          list += "��    �@�B����y��L���ؿv�C                                ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      case "2":    //�x��.
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                      �x��(Barracks)                      ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    �x��i�H�s�y�M�V�m����Ԥh�A�O�p�����D�n�L�O�ӷ��C    ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      case "3":    //�L�u�t.
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                      �L�u�t(Armory)                      ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    �b�L�u�t�ݯ}���𤺡A�a�y�H����Ǯa�̤��������թM��    ��\n";
          list += "��    �s�U���U�˪��j�¤O�������L���A���U���������Z���C      ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      case "4":    //�˥Ҭ�o
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��              �˥Ҭ�o����(Armor Place)                   ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    �˥Ҭ�o���ߤ����۳\\�h��Ǯa�b��o�s�y��㨾�m�O��    ��\n";
          list += "��    �˥Ҩ���C                                            ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      case "5":    //�u�t.
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                      �u�t(Factory)                       ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    �o�ӥ��j���۰ʤu�t�O�Ҧ��a�y�H�a�������Ͳ����a��C    ��\n";
          list += "��    �q���t�����ʸ˥Ҩ��A��¤O�j�j���𫰩Z�J�C            ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      case "6":    //��s�|.
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                      ��s��(Academy)                     ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    ��s�|�D�n��s�p��j�ƪZ�������O�M�[�j�Ԥh���԰���    ��\n";
          list += "��    �O�C                                                  ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      case "7":    //�ɵ���.
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                   �ɵ���(Supply Depot)                   ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    �ɵ����D�n�\\��O�N���l������Ԥh�״_�A�M�s�y�o���@    ��\n";
          list += "��    �ǾԳ��W���{�ɭ״_�u��C                              ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      case "8":   //�Ӫů�.
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                    �Ӫů�(Starport)                      ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��    �o�إ��j�B���i���Ӫů��i�H�Ͳ��Ҧ��p���ϥΪ��ӪŲ�    ��\n";
          list += "��    ĥ�C                                                  ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      default:
          message_vision("\n",me);
          list = "\n";
          list += "��������������������������������������������������������������\n";
          list += "��                        �ؿv������:                       ��\n";
          list += "��w�w�w�w�w�w�w�w�w�w�w�w�w�w�ޢw�w�w�w�w�w�w�w�w�w�w�w�w�w��\n";
          list += "��1.  ��������(Command Center)��2.  �x��(Barracks)          ��\n";
          list += "��3.  �L�u�t(Armory)          ��4.  �˥Ҭ�o��(Armor place) ��\n";
          list += "��5.  �u�t(Factory)           ��6.  ��s��(Academy)         ��\n";
          list += "��7.  �ɵ���(Supply Depot)    ��8.  �Ӫů�(Starport)        ��\n";
          list += "��������������������������������������������������������������\n";
          list += "���Y�ݭn��ؿ�J�G  rebuild <�N��> �Y�i�C                   ��\n";
          list += "���Y���i�@�B�o���ؿv���\\�ο�J�G about <�N��> �Y�i�C        ��\n";
          list += "��������������������������������������������������������������\n";
          list += "\n";
          tell_object(me,list);
          break;
      }
   return 1;
}
