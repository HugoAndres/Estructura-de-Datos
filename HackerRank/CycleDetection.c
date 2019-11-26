bool
has_cycle (SinglyLinkedListNode * head)
{

  int cont = 0;

  if (head == NULL)
    {
      return 0;
    }
  else
    {
      while (1)
	{
	  if (head->next == NULL)
	    {
	      return 0;
	      break;
	    }
	  else if (cont == 1001)
	    {
	      return 1;
	      break;
	    }
	  cont++;
	  head = head->next;
	}
    }
}
