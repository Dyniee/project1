using System;
using System.Collections.Generic;

namespace StoreKoiFish.Reponsitories.Entities;

public partial class Consignment
{
    public int ConsignmentId { get; set; }

    public int? CustomerId { get; set; }

    public int? KoiId { get; set; }

    public DateTime? ConsignmentDate { get; set; }

    public string? Status { get; set; }

    public virtual Customer? Customer { get; set; }

    public virtual Koi? Koi { get; set; }
}
