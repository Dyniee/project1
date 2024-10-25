using System;
using System.Collections.Generic;

namespace StoreKoiFish.Reponsitories.Entities;

public partial class Koi
{
    public int KoiId { get; set; }

    public string? Breed { get; set; }

    public string? Origin { get; set; }

    public string? Gender { get; set; }

    public int? Age { get; set; }

    public decimal? Size { get; set; }

    public string? Personality { get; set; }

    public decimal? FoodPerDay { get; set; }

    public decimal? ScreeningRate { get; set; }

    public decimal? Price { get; set; }

    public string? Status { get; set; }

    public virtual ICollection<Consignment> Consignments { get; set; } = new List<Consignment>();

    public virtual ICollection<Feedback> Feedbacks { get; set; } = new List<Feedback>();

    public virtual ICollection<OrderDetail> OrderDetails { get; set; } = new List<OrderDetail>();
}
