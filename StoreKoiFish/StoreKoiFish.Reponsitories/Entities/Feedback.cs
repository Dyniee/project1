using System;
using System.Collections.Generic;

namespace StoreKoiFish.Reponsitories.Entities;

public partial class Feedback
{
    public int FeedbackId { get; set; }

    public int? CustomerId { get; set; }

    public int? KoiId { get; set; }

    public string? FeedbackText { get; set; }

    public int? Rating { get; set; }

    public string? Response { get; set; }

    public virtual Customer? Customer { get; set; }

    public virtual Koi? Koi { get; set; }
}
