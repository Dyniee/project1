using System;
using System.Collections.Generic;

namespace StoreKoiFish.Reponsitories.Entities;

public partial class Faq
{
    public int FaqId { get; set; }

    public string? Question { get; set; }

    public string? Answer { get; set; }
}
