inherit ITEM;
void create()
{
        set_name("�߲���",({"cat's-eye","eye","cat's"}) );
        set("long",@LONG
�o�O�@���۷�}�����_�ۡA�b�_�۸̭�������¦⪺�ӯ��A������
���רϱo���_�۬ݰ_�Ӹ�ߪ������@�ˬ��R�C
LONG);
        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
  else
   {
          set("value",50000);
          set("unit","��");
        }
        setup();
}
